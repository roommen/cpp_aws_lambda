var pg = require('./node_modules/primegen.node');

exports.handler = function(event, context) {
    pg.calcPrime(event["range"], function(results) {
        context.succeed(results);
    });
};
