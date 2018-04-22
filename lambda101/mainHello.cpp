#include <v8.h>
#include <node.h>
#include <uv.h>
#include <string>
#include <iostream>

#include "hello.h"

using namespace v8;

void saySomething(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = args.GetIsolate();
	args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello World"));
}

void init(Handle <Object> exports, Handle<Object> module) {
	NODE_SET_METHOD(exports, "speak", saySomething);
}

NODE_MODULE(node101, init)
