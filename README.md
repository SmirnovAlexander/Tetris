# Tetris

[![Build Status](https://travis-ci.com/SmirnovAlexander/Tetris.svg?branch=master)](https://travis-ci.com/SmirnovAlexander/Tetris)

Terminal tetris game for *nix operating system

<img src="https://user-images.githubusercontent.com/32129186/82892702-9d1bba80-9f58-11ea-955b-c69c7cabbba9.gif" width="500" />

## Installing

To install tetris execute following commands:

```
$ git clone https://github.com/SmirnovAlexander/Tetris
$ cd Tetris
$ make
```

## Running the tests

To run tests execute:

```
$ make test
```

## Playing

In `Tetris` directory run:

```
$ ./bin/tetris
```

There are 2 sets of controls:
1) Vim-like controls 
    - <kbd>h</kbd> to move piece left
    - <kbd>j</kbd> to move piece down
    - <kbd>k</kbd> to flip piece
    - <kbd>l</kbd> to move piece right
2) Default controls
    - <kbd>a</kbd> to move piece left
    - <kbd>s</kbd> to move piece down
    - <kbd>w</kbd> to flip piece
    - <kbd>d</kbd> to move piece right
    
Also there is a <kbd>space</kbd> to flip the piece for convinience.
    
## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
