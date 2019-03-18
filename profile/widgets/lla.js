var title = "Longitude Latitude Altitude";

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

function main() {
    var llhSat = getGeodesic(ascSat);
    var text = [];
    var wa = [];
    var w, h, dw;
    
    fontSize = parentWidth * 0.0075
    canvas.setFont("Courier", fontSize, 75, false);
    
    text[0] = "LAT " + toDegMin(llhSat[0]);
    text[1] = "LON " + toDegMin(llhSat[1]);
    text[2] = "ALT " + toKm(llhSat[2]);
    
    wa[0] = canvas.textWidth(text[0]);
    wa[1] = canvas.textWidth(text[1]);
    wa[2] = canvas.textWidth(text[2]);
    
    w = Math.max(wa[0], wa[1], wa[2]);
    h = canvas.fontHeight();
    dw = w * 0.05;

    canvas.setSize(w * 1.1, h * 3.3);
    canvas.fill(0x0);
    canvas.setPen(0xFFFFFF);
    canvas.drawText(dw,     h, text[0]);
    canvas.drawText(dw, 2 * h, text[1]);
    canvas.drawText(dw, 3 * h, text[2]);
}

main();
