# from skimage import measure as ssim
# from skimage.measure import structural_similarity as ssim
from skimage.measure import compare_ssim as ssim
import matplotlib.pyplot as plt
import numpy as np
import cv2
import os
import glob
from pathlib import Path

def extract_images():
      print("from image_comparison.py")

      # load image
      file_path = "/Users/noriyukisuzuki/of_v0.9.8_osx/apps/myApps/camera_002/bin/data/*.png"
      pngFiles = glob.glob(file_path)
      latest_file = max(pngFiles, key=os.path.getctime)
      print(latest_file)
      original = cv2.imread("/Users/noriyukisuzuki/of_v0.9.8_osx/apps/myApps/camera_002/bin/data/python/images/01.jpg")
      screenshot = cv2.imread(latest_file)
      cv2.imshow("color", original)
      cv2.imshow("color", screenshot) # only one image showed
      # original = cv2.cvtColor(original, cv2.COLOR_BGR2GRAY)
      # screenshot = cv2.cvtColor(screenshot, cv2.COLOR_BGR2GRAY)
	


# def compare_images(imageA, imageB, title):
# 	# compute the mean squared error and structural similarity
# 	# index for the images
# 	m = mse(imageA, imageB)
# 	s = ssim(imageA, imageB)

# 	# setup the figure
# 	fig = plt.figure(title)
# 	plt.suptitle("MSE: %.2f, SSIM: %.2f" % (m, s))

# 	# show first image
# 	ax = fig.add_subplot(1, 2, 1)
# 	plt.imshow(imageA, cmap = plt.cm.gray)
# 	plt.axis("off")

# 	# show the second image
# 	ax = fig.add_subplot(1, 2, 2)
# 	plt.imshow(imageB, cmap = plt.cm.gray)
# 	plt.axis("off")

# 	# show the images
# 	plt.show()

# def mse(imageA, imageB):
# 	# the 'Mean Squared Error' between the two images is the
# 	# sum of the squared difference between the two images;
# 	# NOTE: the two images must have the same dimension
# 	err = np.sum((imageA.astype("float") - imageB.astype("float")) ** 2)
# 	err /= float(imageA.shape[0] * imageA.shape[1])
	
# 	# return the MSE, the lower the error, the more "similar"
# 	# the two images are
# 	return err
 
# def compare_images(imageA, imageB, title):
# 	# compute the mean squared error and structural similarity
# 	# index for the images
# 	m = mse(imageA, imageB)
# 	s = ssim(imageA, imageB)
 
# 	# setup the figure
# 	fig = plt.figure(title)
# 	plt.suptitle("MSE: %.2f, SSIM: %.2f" % (m, s))
 
# 	# show first image
# 	ax = fig.add_subplot(1, 2, 1)
# 	plt.imshow(imageA, cmap = plt.cm.gray)
# 	plt.axis("off")
 
# 	# show the second image
# 	ax = fig.add_subplot(1, 2, 2)
# 	plt.imshow(imageB, cmap = plt.cm.gray)
# 	plt.axis("off")
 
# 	# show the images
# 	plt.show()


# fig = plt.figure("Images")
# images = ("Original", original), ("Contrast", contrast), ("Photoshopped", shopped)
 