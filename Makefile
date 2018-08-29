all: bin/sort_multi_process bin/sort_single_process

bin/sort_multi_process: src/sort_multi_process.c src/A4_sort_helpers.c 
	gcc src/sort_multi_process.c src/A4_sort_helpers.c -lm  -lpthread -o bin/sort_multi_process

bin/sort_single_process: src/sort_single_process.c src/A4_sort_helpers.c
	gcc src/sort_single_process.c src/A4_sort_helpers.c -lm  -lpthread -o bin/sort_single_process

test_single_short:
	bin/sort_single_process test_inputs/words_short.txt > outputs/out_single_short.txt
	@echo "Checking the diff of out_single_short vs correct sort."
	diff outputs/out_single_short.txt correct/words_short_sorted.txt > /dev/null

test_single_long:
	bin/sort_single_process test_inputs/words_scrambled.txt > outputs/out_single_long.txt
	@echo "Checking the diff of out_single_long vs correct sort."
	diff outputs/out_single_long.txt correct/words_scrambled_sorted.txt	> /dev/null

test_multi_short:
	bin/sort_multi_process test_inputs/words_short.txt > outputs/out_multi_short.txt
	@echo "Checking the diff of out_multi_short vs correct sort."
	diff outputs/out_multi_short.txt correct/words_short_sorted.txt > /dev/null

test_multi_long:
	bin/sort_multi_process test_inputs/words_scrambled.txt > outputs/out_multi_long.txt
	@echo "Checking the diff of out_multi_long vs correct sort."
	diff outputs/out_multi_long.txt correct/words_scrambled_sorted.txt > /dev/null

clean:
	rm -rf bin/sort_single_process bin/sort_multi_process outputs/*

