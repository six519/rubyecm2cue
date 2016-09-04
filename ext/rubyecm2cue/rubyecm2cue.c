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
    char *retValue = "";
    char *infilename = StringValueCStr(arg_path);;
    char *outfilename;
    char *oldfilename;
    int unecm_ret = 0;

    FILE *fin, *fout, *cue_file;

    eccedc_init();

    if(strlen(infilename) < 5) {
      strcpy(retValue, "filename is too short");
      return rb_str_new_cstr(retValue);
    }
    if(strcasecmp(infilename + strlen(infilename) - 4, ".ecm")) {
      strcpy(retValue, "filename must end in .ecm");
      return rb_str_new_cstr(retValue);
    }

    outfilename = malloc(strlen(infilename) - 3);
    oldfilename = malloc(strlen(infilename) - 3);
    if(!outfilename) abort();
    memcpy(outfilename, infilename, strlen(infilename) - 4);
    outfilename[strlen(infilename) - 4] = 0;

    fprintf(stderr, "Decoding %s to %s.\n", infilename, outfilename);

    fin = fopen(infilename, "rb");
    if(!fin) {
      strcpy(retValue, "Cannot open file");
      return rb_str_new_cstr(retValue);
    }
    fout = fopen(outfilename, "wb");
    if(!fout) {
      strcpy(retValue, "Cannot write file");
      fclose(fin);
      return rb_str_new_cstr(retValue);
    }

    unecm_ret = unecmify(fin, fout);

    fclose(fout);
    fclose(fin);

    if(unecm_ret != 0) {
      strcpy(retValue, "Cannot decode file");
      return rb_str_new_cstr(retValue);
    }

    strcpy(oldfilename, outfilename);
    cue_file = fopen(strcat(outfilename, ".cue"), "w");
    if(!cue_file) {
      strcpy(retValue, "Cannot write cue file");
      return rb_str_new_cstr(retValue);
    }
    fprintf(cue_file, "FILE \"%s\" BINARY\n", oldfilename);
    fprintf(cue_file, "\tTRACK 01 MODE1/2352\n");
    fprintf(cue_file, "\t\tINDEX 01 00:00:00");
    fclose(cue_file);

    strcpy(retValue, outfilename);
    return rb_str_new_cstr(retValue);
}
