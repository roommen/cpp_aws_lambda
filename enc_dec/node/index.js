var custDec = require('./node_modules/custDec.node');

exports.handler = function(event, context) {
    custDec.fileDecrypt(event["fileName"], function(results) {
        context.succeed(results);
    });
};
