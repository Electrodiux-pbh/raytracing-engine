import cv2
import os

image_folder = 'frames'
video_name = 'video.avi'

images = [img for img in os.listdir(image_folder) if img.endswith(".png")]
frame = cv2.imread(os.path.join(image_folder, images[0]))
height, width, layers = frame.shape

video = cv2.VideoWriter(video_name, 0, 24, (width,height))

# Sort the images by name before adding them to the video
images.sort(key=lambda x: int(x.split('.')[0].split('-')[1]))

for image in images:
    video.write(cv2.imread(os.path.join(image_folder, image)))

cv2.destroyAllWindows()
video.release()