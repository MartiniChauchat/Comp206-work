# Comp206-work
## description: 
assignments did in comp206 class

### q1_julia_explorer
substitute the value of a and b in the file **shape_template.txt**, and print out the new txt file
```
  gcc q1_julia_explorer.c
  ./a.out shape_template.txt [newvalue_a] [newvalue_b]
```

### q2_calendar
print a command line calendar of chosen size.
```
  gcc q2_calendar.c 
  ./a.out [max number of characters displayed for every weekday] [day of the firstday of the year] 
```

### Bmp editing 
edit a bitmap file
- part 1 : display a bitmap's info 
```
gcc bmp_info.c A2_bmp_helpers.c -o bmp_info
./bmp_info [bmp file]
```
- part 2 : change the specific part of the image to another color, and make a new bmp file
```
gcc bmp_mask.c A2_bmp_helpers.c -o bmp_mask
./bmp_mask [input bmp] [output bmp] [x_1] [x_2] [y_1] [y_2] [Red] [Green] [Blue]
```
- part 3 : collage different bmp into one piece 
here is an example included
```
gcc bmp_collage.c A2_bmp_helpers.c -o bmp_collage
./bmp_collage metro_top_left.bmp metro_top_right.bmp metro_collage.bmp 65 135
```
