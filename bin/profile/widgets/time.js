var	title = "UTC = Day of Year/Time";

function sqr(x) {
	return x*x;
}

function getAer(xyzSat, xyzLoc) {
	var j, i, s;
	var aerv = new Array(0.0, 0.0, 0.0, 0.0);
	var p = Math.sqrt(xyzLoc[0]*xyzLoc[0] + xyzLoc[1]*xyzLoc[1]);
	var r = Math.sqrt(xyzLoc[0]*xyzLoc[0] + xyzLoc[1]*xyzLoc[1] + xyzLoc[2]*xyzLoc[2]);
	aerv[2] = Math.sqrt(sqr(xyzLoc[0] - xyzSat[0]) + sqr(xyzLoc[1] - xyzSat[1]) + sqr(xyzLoc[2] - xyzSat[2]));

	if (p == 0) return aerv;
	var m = new Array();
	for (i = 0; i < 3; i++)
		m[i] = new Array(0.0, 0.0, 0.0);
	
	m[0][0] = -xyzLoc[1]/p;
	m[0][1] = xyzLoc[0]/p;
	m[0][2] = 0.0;
	m[1][0] = -(xyzLoc[0]*xyzLoc[2]/(p*r));
	m[1][1] = -(xyzLoc[1]*xyzLoc[2]/(p*r));
	m[1][2] = p/r;
	m[2][0] = xyzLoc[0]/r;
	m[2][1] = xyzLoc[1]/r;
	m[2][2] = xyzLoc[2]/r;

	var d = new Array(0.0, 0.0, 0.0);
	for (j = 0; j < 3; j++)
		for (i = 0; i < 3; i++) d[j] += (xyzSat[i] - xyzLoc[i])*m[j][i];

	s = d[2]/Math.sqrt(d[0]*d[0] + d[1]*d[1] + d[2]*d[2]);

	if (s == 1.0) aerv[1] = 0.5*Math.PI; else aerv[1] = Math.atan(s/Math.sqrt(1.0 - s*s));

	if (d[1] == 0) {
		if (d[0] > 0) aerv[0] = 0.5*Math.PI; else aerv[0] = 1.5*Math.PI;
		return aerv;
	}
	aerv[0] = Math.atan(d[0]/d[1]);
	if (d[1] < 0) aerv[0] += Math.PI;
	else if ((d[0] < 0)) aerv[0] += 2.0*Math.PI;

	aerv[3] = ((xyzSat[0] - xyzLoc[0])*(xyzSat[3] - xyzLoc[3]) + (xyzSat[1] - xyzLoc[1])*(xyzSat[4] - xyzLoc[4]) + (xyzSat[2] - xyzLoc[2])*(xyzSat[5] - xyzLoc[5]))/aerv[2];

	return aerv;
}

function getGeodesic(r) {
	//latitude longitude height
	var llh = new Array(0.0, 0.0, 0.0);
  	var p, T, sT, cT, N;
	const WZ = 7.2921151467e-5;
	const a_axis = 6378137.0;   //WGS-84 earth's semi major axis
	const b_axis = 6356752.31;  //WGS-84 earth's semi minor axis
	//first  numerical eccentricity
	const e1sqr = ((a_axis * a_axis - b_axis * b_axis) / (a_axis * a_axis));
//	//second numerical eccentricity
	const e2sqr = ((a_axis * a_axis - b_axis * b_axis) / (b_axis * b_axis));

  	p = Math.sqrt(r[0] * r[0] + r[1] * r[1]);
  	T = Math.atan(r[2] * a_axis / (p * b_axis));
  	sT = Math.sin(T);
  	cT = Math.cos(T);
  	llh[0] = Math.atan((r[2] + e2sqr * b_axis * sT * sT * sT) / (p - e1sqr * a_axis * cT * cT * cT));
  	
  	if (r[0] == 0.0) llh[1] = Math.PI / 2.0;
  	else             llh[1] = Math.atan(r[1] / r[0]);

  	if (r[0] < 0 && r[1] > 0) llh[1] += Math.PI;
    if (r[0] < 0 && r[1] < 0) llh[1] -= Math.PI;
    var t = 0;
    var gsto = 0;
    llh[1] += -WZ*t*60.0 - gsto;
    llh[1] = (llh[1] + 3*Math.PI)%(2*Math.PI) - Math.PI;
    if (llh[1] < -Math.PI) llh[1] += 2*Math.PI;

    N = a_axis / Math.sqrt(1.0 - e1sqr * Math.sin(llh[0]) * Math.sin(llh[0]));
  	llh[2] = p / Math.cos(llh[0]) - N;
  	return llh;
}

function toKm(value) {
	return Number(value/1000.0).toFixed(3) + " km";
}

function toKmSec(value) {
	return Number(value/1000.0).toFixed(3) + " km/sec";
}

function toDegMin(value) {
	var tmp = value*180.0/Math.PI;
	var deg = Math.floor(tmp) + "\xb0 " + Number((tmp - Math.floor(tmp))*60).toFixed(3) + "\'";
	return deg;
}

function main() {
	var aerv = getAer(ascSat, ascLoc);
	var llhSat = getGeodesic(ascSat);
	var llhLoc = getGeodesic(ascLoc);
	canvas.setPos((parentWidth - 176)/2, 32);
	canvas.setSize(176, 24);
	canvas.fill(0xF40000);
	canvas.setMaskColor(0xF40000);
	canvas.setPen(0xFF0000);
	canvas.setFont("Arial", 16, 75, false);
	var now = new Date();
	now.setTime(timeNow*1000);
	var doy = new Date(now.getFullYear(), 0, 1);
	doy = Math.ceil((now - doy)/86400000);
	doy = "000" + doy;
	doy = doy.substr(doy.length - 3);
	hours = "00" + now.getUTCHours();
	hours = hours.substr(hours.length - 2);
	minutes = "00" + now.getUTCMinutes();
	minutes = minutes.substr(minutes.length - 2);
	canvas.drawText(0, 18, "UTC = " + doy + "/" + hours + ":" + minutes);
}

main();
