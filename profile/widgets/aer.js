var title = "Azimuth Elevation Range Velocity";

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

function main() {
    var aerv = getAer(ascSat, ascLoc);
    
    var text = [];
    var wa = [];
    var w, h, dw;
    
    fontSize = parentWidth * 0.0075
    canvas.setFont("Courier", fontSize, 75, false);
    
    text[0] = "AZM " + toDegMin(aerv[0]);
    text[1] = "ELV " + toDegMin(aerv[1]);
    text[2] = "RNG " + toKm(aerv[2]);
    text[3] = "VEL " + toKmSec(aerv[3]);
    
    wa[0] = canvas.textWidth(text[0]);
    wa[1] = canvas.textWidth(text[1]);
    wa[2] = canvas.textWidth(text[2]);
    wa[3] = canvas.textWidth(text[3]);
    
    w = Math.max(wa[0], wa[1], wa[2], wa[3]);
    h = canvas.fontHeight();
    dw = w * 0.05;
    w *= 1.1
    
    canvas.setSize(w, h * 4.4);
    canvas.setPos(parentWidth - w, 0);
    canvas.fill(0x0);
    canvas.setPen(0xFFFFFF);
    canvas.drawText(dw,     h, text[0]);
    canvas.drawText(dw, 2 * h, text[1]);
    canvas.drawText(dw, 3 * h, text[2]);
    canvas.drawText(dw, 4 * h, text[3]);
}

main();
