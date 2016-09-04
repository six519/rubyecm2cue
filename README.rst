rubyecm2cue
===========

Ruby Extension In C To Decode ECM File And Generate Cue File. Code tested in OSX 0.11.6.

Installing
==========
::

    gem install rubyecm2cue

Ruby Sample Usage
=================
::

    require 'rubyecm2cue'
    include RubyEcm2Cue
    data = process "Tekken 3 (E) (Track 1) [SCES-01237].bin.ecm"