# Lem_in 

<img width="100%" src="Lem_in_img.png"/>

## Pitch

Lem_in is a pedagogical project from 42 School which aims to introduce the students to graphing algorithms. An ant colony must move from one point to another. The aim is to make the shortest path possible. The program have to intelligently select the precise paths and movements that these ants must take.

## Main features

- Breadth-first search algorithm
- Visualisation 
- Speed
- Script : run all maps (valid and invalid)

<img align="center" src="https://gfycat.com/heartfeltsmoggygreyhounddog.gif" width ="100%" />

## Things I have learned

- Better understanding of the C programming language and how to structure the code to keep a growing program maintanable, and open to new features.
- Selecting a searching algorithm (Breadth-first search) and implementing it through a clean code structure. 
- Use of MLX library, working with visuals using code.
- Use keyboard as controler, dealing with events in real time.

## Compile and run

If ./lem_in does not exist use make.
Then run './lem_in -v < <file>' test maps in ./tests/ -v for visualizer

example :
	
	make
	./lem_in -v < ./tests/good_tests/42_easy

## Script

To run all maps use scripts

example :

	cd scripts
	./good_tests.sh

## Keys

- M : Menu
- → : Faster
- ← : Slower
- P : Pause
- R : Reset
- \<esc\> : Quit
