Plexability
===========

Be plexable.

Note that this project currently only supports OS X.  It's being built in the
hopes of working across multiple platforms, but none of that work has happened
yet.


Hacking On Plexability
----------------------

Brace yourself.  Chromium is a **huge** project, and Plexability depends on most
of it.  Set aside a few hours to download and build the source the first time.

Thankfully, the process is automated:

1. Check out the Plexability source to a directory of your choosing.
2. Run `python -m tools/sync`


License
-------

Plexability is licensed under
[GNU General Public License (GPL) version 2](GPLv2-LICENSE.md) or later.

While I'd like to provide a more permissive license, Plexability makes use of -
and builds upon - several great GPL-licensed libraries.  Of particular note:

* [XBMC (and Plex)](http://xbmc.org/team-xbmc/2003/10/31/please-respect-the-gpl-license/)
* [ffmpeg and it's GPL-licensed codecs](http://www.ffmpeg.org/legal.html)
