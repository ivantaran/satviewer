var    title = "UTC = Day of Year/Time";

function main() {
    var now = new Date();
    now.setTime(timeNow * 1000);
    var doy = new Date(now.getFullYear(), 0, 1);
    doy = Math.ceil((now - doy) / 86400000);
    doy = "000" + doy;
    doy = doy.substr(doy.length - 3);
    hours = "00" + now.getUTCHours();
    hours = hours.substr(hours.length - 2);
    minutes = "00" + now.getUTCMinutes();
    minutes = minutes.substr(minutes.length - 2);
    text = "UTC = " + doy + "/" + hours + ":" + minutes;
    fontSize = parentWidth * 0.01
    canvas.setFont("Courier", fontSize, 75, false);
    w = canvas.textWidth(text);
    h = canvas.fontHeight();
    w = w * 1.1;
    h = h * 1.4;
    dw = w * 0.05;
    dh = h * 0.2;
    canvas.setPos((parentWidth - w) * 0.5, parentHeight * 0.04);
    canvas.setSize(w, h);
    canvas.fill(0xF40000);
    canvas.setMaskColor(0xF40000);
    canvas.setPen(0xFF0000);
    canvas.drawText(dw, h - dh, text);
}

main();
