#include "ruby.h"
#include <stdio.h>
#include "unecm.h"

VALUE RubyEcm2Cue = Qnil;
void Init_rubyecm2cue();
VALUE method_process(VALUE, VALUE);

void Init_rubyecm2cue(){
    VALUE RubyEcm2Cue = rb_define_module("RubyEcm2Cue");
    rb_define_method(RubyEcm2Cue, "process", method_process, 1);
}

VALUE method_process(VALUE self, VALUE arg_path) {
    const char *img= StringValueCStr(arg_path);
    const char *retValue;

    return rb_str_new_cstr(retValue);
}
