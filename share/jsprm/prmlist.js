
var    colorRowState = true;
var    colorRowValues = new Array ("#DDDDFF", "#EEEEFF", "#DDFFDD", "#FFDDDD");
    
function colorRow() {
    colorRowState = colorRowState ^ true;
    if (colorRowState) return colorRowValues[0];
    else return colorRowValues[1];
}

function getGeodesic(r) {
    //latitude longitude height
    var llh = new Array(0.0, 0.0, 0.0);
    var p, T, sT, cT, N;
    
    /* const can't support */
    var WZ = 7.2921151467e-5;
    var a_axis = 6378137.0;   //WGS-84 earth's semi major axis
    var b_axis = 6356752.31;  //WGS-84 earth's semi minor axis
    //first  numerical eccentricity
    var e1sqr = ((a_axis * a_axis - b_axis * b_axis) / (a_axis * a_axis));
    //second numerical eccentricity
    var e2sqr = ((a_axis * a_axis - b_axis * b_axis) / (b_axis * b_axis));
    /**********************/
    
    p = Math.sqrt(r[0] * r[0] + r[1] * r[1]);
    T = Math.atan(r[2] * a_axis / (p * b_axis));
    sT = Math.sin(T);
    cT = Math.cos(T);
    llh[0] = Math.atan2((r[2] + e2sqr * b_axis * sT * sT * sT),
        (p - e1sqr * a_axis * cT * cT * cT));
      
    llh[1] = Math.atan2(r[1], r[0]);

    var t = 0.0;
    var gsto = 0.0;
    llh[1] += -WZ * t * 60.0 - gsto;
    llh[1] = (llh[1] + 3.0 * Math.PI) % (2.0 * Math.PI) - Math.PI;
    if (llh[1] < -Math.PI) llh[1] += 2.0 * Math.PI;

    N = a_axis / Math.sqrt(1.0 - e1sqr * Math.sin(llh[0]) * Math.sin(llh[0]));
    llh[2] = p / Math.cos(llh[0]) - N;
    return llh;
}

function getAer(xyzSat, xyzLoc) {
    var j, i, s;
    var aerv = new Array(0.0, 0.0, 0.0, 0.0);
    var m = new Array();
    var d = new Array(0.0, 0.0, 0.0);
    var p = Math.sqrt(xyzLoc[0] * xyzLoc[0] + xyzLoc[1] * xyzLoc[1]);
    var r = Math.sqrt(xyzLoc[0] * xyzLoc[0] + xyzLoc[1] * xyzLoc[1] + xyzLoc[2] * xyzLoc[2]);
    var dd = new Array(
            xyzLoc[0] - xyzSat[0], 
            xyzLoc[1] - xyzSat[1], 
            xyzLoc[2] - xyzSat[2], 
            xyzLoc[3] - xyzSat[3], 
            xyzLoc[4] - xyzSat[4], 
            xyzLoc[5] - xyzSat[5]
        );

    aerv[2] = Math.sqrt(dd[0] * dd[0] + dd[1] * dd[1] + dd[2] * dd[2]);

    if (p < Number.EPSILON || r < Number.EPSILON) {
        return aerv;
    }

    for (i = 0; i < 3; i++) {
        m[i] = new Array(0.0, 0.0, 0.0);
    }
    
    m[0][0] = -xyzLoc[1] / p;
    m[0][1] = xyzLoc[0] / p;
    m[0][2] = 0.0;
    m[1][0] = -(xyzLoc[0] * xyzLoc[2] / (p * r));
    m[1][1] = -(xyzLoc[1] * xyzLoc[2] / (p * r));
    m[1][2] = p / r;
    m[2][0] = xyzLoc[0] / r;
    m[2][1] = xyzLoc[1] / r;
    m[2][2] = xyzLoc[2] / r;

    for (j = 0; j < 3; j++) {
        for (i = 0; i < 3; i++) {
            d[j] += (xyzSat[i] - xyzLoc[i]) * m[j][i];
        }
    }
    
    s = d[2] / Math.sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);

    aerv[1] = Math.atan2(s, Math.sqrt(1.0 - s * s));
    aerv[0] = Math.atan2(d[0], d[1]);
    aerv[3] = (dd[0] * dd[3] + dd[1] * dd[4] + dd[2] * dd[5]) / aerv[2];

    return aerv;
}

function toKm(value) {
    return Number(value * 0.001).toFixed(3) + " km";
}

function toKmSec(value) {
    return Number(value * 0.001).toFixed(3) + " km/sec";
}

function truncate(number) {
    return number > 0.0 ? Math.floor(number) : Math.ceil(number);
}

function toDegMin(value) {
    value *= 180.0 / Math.PI;
    var deg = truncate(value );
    var line = deg + "\xb0" + 
            Number(Math.abs(value - deg) * 60.0).toFixed(2) + "\'";
    return line;
}

function getRowTable(title, value, color) {
    var row = 
    "<tr BGCOLOR='" + color + "'>" +
    "<td>" + title + "</td>" +
    "<td>" + value + "</td>" +
    "</tr>";
    return row;
}

function getRowHeader(title, red) {
    var color = colorRowValues[2];
    if (red) color = colorRowValues[3];
    var row = 
    "<tr BGCOLOR='" + color + "'>" +
    "<th colspan=2>" + title + "</th>" + 
    "</tr>";
    return row;
}

function main() {
    var aerv = getAer(ascSat, ascLoc);
    var llhSat = getGeodesic(ascSat);
    var llhLoc = getGeodesic(ascLoc);
    var table = 
        "<table BORDER=0 CELLPADDING=0 CELLSPACING=1 WIDTH=100%>" +
            getRowHeader(nameLoc + " - " + nameSat, true) +
            getRowHeader("Current time") +
            getRowTable("UTC"  , timeCurrent, colorRow()) +
            getRowHeader("Targeting") +
            getRowTable("Azimuth"  , toDegMin(aerv[0]), colorRow()) +
            getRowTable("Elevation", toDegMin(aerv[1]), colorRow()) +
            getRowTable("Range"    , toKm(aerv[2])    , colorRow()) +
            getRowTable("Velocity" , toKmSec(aerv[3]) , colorRow()) +
            getRowTable(""         , ""               , colorRow()) +
            
            getRowHeader(nameSat, true) +
            getRowHeader("Geodesic") +
            getRowTable("Latitude"  , toDegMin(llhSat[0])   , colorRow()) +
            getRowTable("Longitude" , toDegMin(llhSat[1])   , colorRow()) +
            getRowTable("Altitude"    , toKm(llhSat[2])       , colorRow()) +
            getRowTable(""          , ""                    , colorRow()) +

            getRowHeader("CCS") +
            getRowTable("X" , toKm(ascSat[0])   , colorRow()) +
            getRowTable("Y" , toKm(ascSat[1])   , colorRow()) +
            getRowTable("Z" , toKm(ascSat[2])   , colorRow()) +
            getRowTable("Vx", toKmSec(ascSat[3]), colorRow()) +
            getRowTable("Vy", toKmSec(ascSat[4]), colorRow()) +
            getRowTable("Vz", toKmSec(ascSat[5]), colorRow()) +
            getRowTable(""  , ""                , colorRow()) +

            getRowHeader(nameLoc, true) +
            getRowHeader("Geodesic") +
            getRowTable("Latitude"  , toDegMin(llhLoc[0])   , colorRow()) +
            getRowTable("Longitude" , toDegMin(llhLoc[1])   , colorRow()) +
            getRowTable("Altitude"    , toKm(llhLoc[2])       , colorRow()) +
            getRowTable(""          , ""                    , colorRow()) +
            
            getRowHeader("CCS") +
            getRowTable("X" , toKm(ascLoc[0])   , colorRow()) +
            getRowTable("Y" , toKm(ascLoc[1])   , colorRow()) +
            getRowTable("Z" , toKm(ascLoc[2])   , colorRow()) +
            getRowTable(""  , ""                , colorRow()) +
        "</table>";

    document.append(table);
}

main();
