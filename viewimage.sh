#!/bin/bash

#usage: ./viewimage test_number

input_image=images/img$1.jpg
input_file=input/in$1
output_file=output/out$1
output_img=images_out/img_out$1.jpg

make
mkdir -p images_out
mkdir -p output

./tema1 < $input_file > $output_file
python matrixtoimage.py -i $output_file -o $output_img -f $input_image
