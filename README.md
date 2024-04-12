# C on the Microbit

This is copied from
[lancaster-university/microbit-v2-samples](https://github.com/lancaster-university/microbit-v2-samples)
with a few tweaks.

Here are the steps to build and run an executable on the Microbit.

1. Plug the Microbit into your computer. Ensure you see a removable drive (like
   a USB stick).
2. Make sure Docker is installed and started.
3. Open a terminal in this directory.
4. Run `docker build -t microbit-tools --output out .`
5. Check that it succeeds.
6. Open up the `out` directory in Finder.
7. Drag and drop `MICROBIT.hex` into the removable drive.
8. Wait a moment and it will run automatically.

## Development

The code is in `source`. The entrypoint (first file that runs) is `main.c`.

The Microbit Software Development Kit (SDK) uses C++. You can just use C++ if
you like (see the [original
repo](https://github.com/lancaster-university/microbit-v2-samples) for that),
but I wanted to see if we could get C running.

It is possible to use C, but with one major quirk. The C++ SDK uses
object-oriented programming, and C doesn't support that.

To use C, we need to create a 'bridge' between the world of C and C++. You can
find a simple version of this bridge (with just three functions) in
`bridge.cpp`/`bridge.h`. These files represent a list of procedural functions,
written in C++, that wrap up bits of the C++ SDK in a functions C can then call.

You can see these being used in `main.c` — which is our C file.
