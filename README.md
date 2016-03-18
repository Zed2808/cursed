Cursed
======
**Cursed** will be a text based adventure game built on the Linux [Ncurses](https://www.gnu.org/software/ncurses/) library, with Windows support through [PDCurses](http://pdcurses.sourceforge.net/).

Screenshots
--------

![](http://i.imgur.com/m3LUavT.png)
![](http://i.imgur.com/Lm235iY.png)
![](http://i.imgur.com/KJIm6Ii.png)

Building
--------
**Cursed** can currently be built on Linux or Windows with the included makefile.

If compiling on Linux, install the ncurses library.

    sudo apt-get install libncurses5

If compiling on Windows, install [PDCurses](http://pdcurses.sourceforge.net/).

Download and compile the source.

    git clone https://github.com/zed2808/cursed.git
    cd cursed
    make
