from scipy.stats import norm

import matplotlib.mlab as mlab
import numpy as np
import matplotlib.pyplot as plt


filename="./weight_distribution/conv_weights.txt"
weight=[]
bias=[]
f_map=[]
title=[]
j=0
k=0
with open( filename )as f:
	all_file=f.readlines()	
	for i in range(1,len(all_file)):
		if( all_file[i].split(": ")[0]=='weight'):
			weight.append(all_file[i+1])
			title.append(all_file[i].split(": ")[1] )
		if(all_file[i] == "bias: \n" ):
			bias.append(all_file[i+1])
		if(all_file[i] == "featuremap: \n" ):
			f_map.append(all_file[i+1])
		
np_weight=[]
np_bias=[]
np_f_map=[]
for layer in weight: 
	w=np.fromstring("".join(layer) ,dtype=float,sep=' ')
	np_weight.append(w)

for layer in bias: 
	b=np.fromstring("".join(layer) ,dtype=float,sep=' ')
	np_bias.append(b)
		
for layer in f_map: 
	f=np.fromstring("".join(layer) ,dtype=float,sep=' ')
	np_f_map.append(f)



for i in range(0,len(weight)):

	#ax = fig.add_subplot(1,1,1)
	
	fig, axes = plt.subplots(nrows=1, ncols=3 ,figsize=(10,6))
	fig.suptitle('convolution at layer '+ title[i], fontsize=26)
	fig.subplots_adjust(top=0.8)#adjust sub plot
	ax0, ax1, ax2 = axes.flatten()


	'''
	y=np_weight[i]
	x=np_bias[i]
	z=np_f_map[i]
	fig = plt.figure()
	ax = fig.add_subplot(111)
	ax.hist(x, 50, density=True)
	ax.hist(y, 50, density=True)
	ax.hist(z, 50, density=True)
	fig.canvas.draw()
	'''
	x=np_bias[i]
	y=np_weight[i]
	z=np_f_map[i]
	'''
	plt.hist(x,50, normed=1, alpha=0.5, label='bias')
	plt.hist(y,50, normed=1, alpha=0.5, label='weight')
	plt.hist(z,50, normed=1, alpha=0.5, label='feature map')
	'''

		
	n, bins, patches = ax0.hist(x, 30,density=True , histtype='bar' )
	(mu, sigma) = norm.fit(x)
	t = mlab.normpdf( bins, mu, sigma)
	#l = ax0.plot(bins, t, 'r--', linewidth=2)

	ax0.set_title('bias')

	weights = np.ones_like(y)/float(len(y))

	n, bins, patches = ax1.hist(y, 30 , histtype='bar',weights=weights )
	(mu, sigma) = norm.fit(y)
	t = mlab.normpdf( bins, mu, sigma)
	#l = ax1.plot(bins, t, 'r--', linewidth=2)
	ax1.set_title('weight')


	n, bins, patches = ax2.hist(z, 30,density=True , histtype='bar' )
	(mu, sigma) = norm.fit(z)
	t = mlab.normpdf( bins, mu, sigma)
	#l = ax2.plot(bins, t, 'r--', linewidth=2)
	ax2.set_title('feature map')

	#fig.tight_layout()


	#plt.legend(loc='upper right')
	plt.show()
	fig.savefig( "tmp.png"   )


