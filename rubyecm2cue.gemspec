Gem::Specification.new do |s|
    s.name = "rubyecm2cue"
    s.version = "1.0.2"
    s.date = "2016-09-04"
    s.authors = ["Ferdinand E. Silva"]
    s.email = "ferdinandsilva@ferdinandsilva.com"
    s.summary = "Ruby Extension In C To Decode ECM File And Generate Cue File"
    s.homepage = "http://ferdinandsilva.com"
    s.description = "Ruby Extension In C To Decode ECM File And Generate Cue File"
    s.files = ["ext/rubyecm2cue/rubyecm2cue.c", "ext/rubyecm2cue/extconf.rb", "ext/rubyecm2cue/unecm.h", "ext/rubyecm2cue/unecm.c"]
    s.extensions = %w[ext/rubyecm2cue/extconf.rb]
end