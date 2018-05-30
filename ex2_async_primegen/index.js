var node102 = require('./node_modules/node102.node');

exports.handler = function(event, context) {
    node102.calcPrime(event["primeLimit"], function(results) {
        context.succeed(results);
    });
};
