Gem::Specification.new do |s|
    s.name = "rubyecm2cue"
    s.version = "1.0.0"
    s.date = "2016-09-04"
    s.authors = ["Ferdinand E. Silva"]
    s.email = "ferdinandsilva@ferdinandsilva.com"
    s.summary = ""
    s.homepage = "http://ferdinandsilva.com"
    s.description = ""
    s.files = ["ext/rubyecm2cue/rubyecm2cue.c", "ext/rubyecm2cue/extconf.rb", "ext/rubyecm2cue/unecm.h", "ext/rubyecm2cue/unecm.c"]
    s.extensions = %w[ext/rubyecm2cue/extconf.rb]
end