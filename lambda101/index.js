var node101 = require('node101');

exports.handler = function(event, context) {
    console.log("sample log");
    context.succeed(node101.speak());
};
