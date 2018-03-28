galaxy-desktop
==============

Quick hack that mixes-and-matches components from various desktop
environments.

**Be warned:** Most likely you *do not* want to use this.

Why?
----

- For most of it, I like the UX of GNOME. But GNOME Shell feels slooooow:
  response/latency to input is “meh” at best, and memory usage is... well,
  let's say that in retrospective using JavaScript might not have been a
  great idea.
- [Budgie](https://github.com/budgie-desktop/budgie-desktop) demostrated that
  `libmutter` can be put to use to write a fast compositor. Unfortunately it
  will stop using GTK+ and GNOME components in version 11, and anything that
  doesn't use GTK+ 3.x is more or less broken when using a HiDPI display.
- At some point I tried the Pantheon shell, which ships with
  [Elementary](https://elementary.io/). While quite neat inside Elementary,
  when using their own applications and GTK+ theme modern GTK+/GNOME
  applications will have visual glitches with most third-party themes, and
  even with the default Adwaita theme. Wingpanel and Switchboard were crashing
  very often, and many things wouldn't work (which I blame on trying things
  on Arch Linux instead of going full Elementary).
- Some of Pantheon's components are quite self-contained, and run happily
  without the rest of the DE. Prime examples are the Gala compositor and
  the Plank panel.


Components
----------

The following are needed at runtime:

- Gala 0.3 or newer.
- Plank 0.11 or newer.
- gnome-control-center 3.28 or newer.
- gnome-settings-daemon 3.28 or newer.
- mate-screensaver 1.20 or newer (works better than gnome-screensaver

Additionally, I tend to use the following as well:

- Many GNOME core applications: Nautilus, Epiphany, Eog...
- [Termite](https://github.com/thestinger/termite/), which can do many things
  with the keyboard.
- [Synapse](https://launchpad.net/synapse-project). While
  [ULauncher](https://ulauncher.io/) looks sleeker and is better maintained,
  it takes more than double the amoun of memory compared to Synapse.


Shortcomings
------------

This frankendesktop is quite rough on the edges, and there are a few
shortcomings you may want to be aware of — this is not just for anybody!

- No UI for configuration. `dconf-editor` is your friend, or even using
  `gsettings` in the command line if that's how you roll.
- No panel with application menus. I'm currently shopping for one,
  `budgie-panel` kinda works but I would like something simple which can
  autohide, show tasks for the current desktop, have an area for status
  icons, clock/calendar, and has an applications menu. Bonus points if it
  can take the applications menus using D-Bus and display them.

