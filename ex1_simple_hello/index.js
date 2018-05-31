var sh = require('./node_modules/sayhello.node');

exports.handler = function(event, context) {
    sh.helloName(event["name"], function(results) {
        context.succeed(results);
    });
};
