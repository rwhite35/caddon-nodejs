// calculate.cc
#include <node.h>
namespace calculate {
	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::Number;
	using v8::Value;

	/**
	 * Method computes a number and then sends that value
	 * to JavaScript. This could then be used to trigger some JS work.
	 * @return Number as product of methods calculation
	 */
	void Method(const FunctionCallbackInfo<Value>&args) {

		Isolate* isolate = args.GetIsolate();

		int i;
		int vec=10;
		double x=10.1, y=20.2;

		// add y to base x this vector of times
		for(i=0; i<vec; i++) {
			x += y;
		}

		// assing the total to args
		auto total = Number::New(isolate, x);
		args.GetReturnValue().Set(total);
	}

	/**
	 * NodeJS bindable exports.method called from Node to initialize addon.
	 * C++ method names that are bound to a Node export name for JS access
	 */
	void Init(Local<Object> exports) {
		NODE_SET_METHOD(exports, "calcInC", Method); // calcInC is called from Javascript
	}

	// a bindable module method
	NODE_MODULE_X(NODE_GYP_MODULE_NAME, Init, NULL, 0);
}
