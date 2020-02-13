import os, sys, getopt
def main(argv):
	try:
		opts, args = getopt.getopt(argv,"hi:o:f:",["ifile=","ofile="])
	except getopt.GetoptError:
		print 'matrixtoimage.py -i <inputfile> -o <outputfile>'
		sys.exit(2)
	for opt, arg in opts:
		if opt == '-h':
			print 'matrixtoimage.py -i <inputfile> -o <outputfile>'
			sys.exit()
		elif opt in ("-f"):
			img = arg
		elif opt in ("-m"):
			m = int(arg)
		elif opt in ("-i"):
			inputfile = arg
		elif opt in ("-o"):
			img_out = arg
	img_file = os.path.expanduser(img)
	from scipy import misc
	A = misc.imread(img_file);
	(m, n, p) = A.shape
	
	import numpy as np
	M = np.zeros((m, n, 3))
	with open(inputfile, 'r') as f :
		for i in range (0, m) :
			for j in range (0, n) :
				line = f.next()
				(r, g, b) = line.split(' ')
				M[i][j][0] = r;
				M[i][j][1] = g;
				M[i][j][2] = b;


	# now display the image from the raw NumPy array:
	from matplotlib import pyplot as PLT
	from matplotlib.colors import hsv_to_rgb
	rgb = hsv_to_rgb(M)
	for i in range (0, m) :
			for j in range (0, n) :
				rgb[i][j][0] = round(rgb[i][j][0] * 255)
				rgb[i][j][1] = round(rgb[i][j][1] * 255)
				rgb[i][j][2] = round(rgb[i][j][2] * 255)
	rgb = rgb.astype(np.uint8)

	misc.imsave(img_out, rgb.astype(np.uint8))
	PLT.imshow(rgb)
	PLT.show()
if __name__ == "__main__":
   main(sys.argv[1:])
