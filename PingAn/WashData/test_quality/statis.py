#coding=utf-8
import os,re,sys,shutil

def read_file(filename):
    with open(filename, 'r') as fp:
        lines = fp.readlines()
        return lines

def main(result_file, threshold):
	lines = read_file(result_file)

	count = 0
	for line in lines:
		segments = line.strip().strip('\n').split('\t')
		if len(segments) < 2:
			print 'segments len  2 '
			continue

		score = float(segments[1])
		if score >= threshold:
			count += 1
	pass_rate = 1.0 * count / len(lines)
	print 'statics result: pass count = {}, total = {}, pass_rate = {}'.format(count, len(lines), pass_rate)


if __name__ == '__main__':
	if len(sys.argv) < 3:
		print 'Usage: python statis.py [result_file] [threshold]'
		sys.exit()

	result_file = sys.argv[1]
	threshold = float(sys.argv[2])

	main(result_file, threshold)