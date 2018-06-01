var sh = require('./node_modules/sayhello.node');

exports.handler = function(event, context) {
    sh.say(event["name"], function(results) {
        context.succeed(results);
    });
};
