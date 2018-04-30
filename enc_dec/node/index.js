var nodedec = require('./node_modules/nodedec.node');

exports.handler = function(event, context) {
    nodeenc.calcPrime(event["fileName"], function(results) {
        context.succeed(results);
    });
};
