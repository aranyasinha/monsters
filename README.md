# monsters
Basic Turn-based combat simulation.
- **Status**: builds but incomplete.

## Origin
It is based on the First generation of Pokemon games (Red & Blue/Green).
Many of the initial work has been adapted directly from their in-game mechanics as it is.

**Caution:** *It is based on my Highschool project which was originally written in C89. Some parts are still in need of being updated for C++11/C++14. The most recent working (and stripped) version is name EDITPKM-1.CPP. It can only be compiled by a C89 compiler with VGA graphics library linked at compile-time.*

## Build Dependencies
You'll need a C++ compiler (gcc/g++ or LLVM clang/clang++) to build it from source as no pre-built binaries are being released, also it builds your character.
minimum required versions: 
 - `gcc` 5.4.0
 - `clang` 3.9

## Build Instructions
you must have git installed for this to work:
```sh
git clone "https://github.com/toxicmender/monsters.git"
cd monsters
./gcc_compile.sh
```

## Usage
Run the `Linux_Binary` inside `binaries` directory to play the game.

## Known Issues
Check the [Issues](https://github.com/toxicmender/monsters/issues) section of the repository.

## Getting Help
If you have questions, concerns, bug reports, etc, please file an issue in the repository's [Issue Tracker](https://github.com/toxicmender/monsters/issues/new)

## Getting involved
Why because it's fun to make games or even just tinker with it to learn about it.
The contribution would be visible [here](https://github.com/toxicmender/monsters/graphs/contributors) along with everyone else who contributed.
There are a huge number of ways to help out:
- If you are **not** a programmer:
  - Help in Documentation
  - Assign relevant labels to open issues (only if you have a basic understanding though)
  - Reporting bugs by creating issues in Issue Tracker (Check [contrib.md](./contrib.md) on how to give useful info)
- If you are a programmer:
  - Read contrib.md it's important to go through it once. Most of the source code formatting is done using clang-format which is a step in the compile script.
  - Fork the repository, clone, checkout into a new branch & start working, staging, commiting. Once you think you're ready for a Pull Request `git pull origin master` & `git rebase -i origin master` then merge your current branch with `master` using `git merge <your_branch> --no-ff`. --no-ff flag prevents fastforward as in squashing all your commits into one merge commit which is important for version control history
  - Create a [Pull Request](https://github.com/toxicmender/monsters/pulls) & graciously wait for a response (adjust anything that maybe asked or clarify reasons). Mind that your pull request shouldn't have merge conflicts in which case it'll be rejected (use `git rebase` & merge then resolve any leftover merge conflicts)

## Roadmap
The project is meant to be a basic framework for any game with similar mechanics and thus needs to be able to allow a more general approach than the current Pokemon based.
The Pokemon specific codes should continue to exist and evolve for referencing use cases for each and every function but in a seperate dev branch than the general one, called pkmn-dev.
If functions &/or mechanics can't be merged with the original one a new fork will be created to accomodate the new ones with adjusted base classes and functions
Please make a fork if you wish to adapt the framework for a game by combining it with some external (non-standard C/C++) library.

# Reference
[Game mechanics](https://serebii.net/games/mechanics.shtml)

## Disclaimer
Although I have mentioned adapting mechanics "as is" they are not representative of actual mechanics but rather supposition of observed behaviour in game.
This Project is in no way meant to be a complete game by itself and thus use of any copyrighted material is strictly forbidden.
