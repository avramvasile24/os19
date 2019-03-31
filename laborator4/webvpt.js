const cproc = require('child_process');
const url = require('url');
const fs = require('fs');

function vpt(query, fncb) {
    const args = [query.h, query.a, query.b, query.c];
    console.log("vpt input:", query, args);
    cproc.execFile("./vpt ", args, (err, stdout) => fncb("vpt ", err, stdout));
}

function writeHtml(res, fileName) {
	res.writeHead(200, {"Content-Type": "text/html"});
	fs.createReadStream(fileName, "UTF-8").pipe(res);
}
function writeError(res) {
    res.writeHead(404, {"Content-Type": "text/plain"});
    res.write("ERROR: page not found");
    res.end();
}
function writeResult(res, fname, err, data) {
    console.log("writeResult", fname);
    console.log(" error:", err);
    console.log(" result:", data.toString());
    res.writeHead(200, {"Content-Type": "text/plain"});
    res.write(data.toString());
    res.end();
}

function handleWebRequest(req, res) {
	console.log("web request", req.url);
        const {pathname, query} = url.parse(req.url, {parseQueryString:true});
	if (pathname === '/')
		writeHtml(res, "./index.html");
    else if (pathname.startsWith("./vpt "))
        vpt(query, (fname, err, data) => writeResult(res, fname, err, data));
    else 
       writeError(res);
}

require("http").createServer (handleWebRequest).listen(8080);

