1. Se debe tomar en cuenta ajustar el volumen de salida de la BB con alsamixer. Para esto se deben modificar los siguientes parametros:
	DAC1 Digital Fine ~ 70
	DAC1 Digital Coarse ~ 50
	Headset ~ 79
	HeadsetL Mixer AudioL1 (on)

2. Es necesario tener los siguientes elementos funcionales en la BB-xM: oggdemux, vorbisdec y audioconvert. Por medio de gst-launch se puede verificar el pipeline de la siguiente manera:
	$ gst-launch filesrc location=archivo.ogg ! oggdemux ! vorbisdec ! audioconvert ! alsasink

3. La compilacion del programa se debe relizar en el PC Host, pero antes se debe verificar que gst.h se encuentre en /usr/include/gstreamer-0.10/gst. Caso contrario, de debe descargar:
	$ sudo apt-get install libgstreamer0.10-dev

4. Ejecutar el make, para crear los ejecutables necesarios.
	$ make		# Crea el ejecutable para la arquitectura ARM. Si el SO de la PC es de 64-bits se dan algunos warnings por el ancho de 				  palabra, ya que el ARM es de 32-bits. De igual manera el ejecutable es funcional.
	$ make x86	# Crea el ejecutable para la arquitectura x86.
	$ make clean	# Elimina los archivos creados en la compilacion.

5. Una vez creado los archivos respectivos se debe ejecutar el programa pasandole como parametro la ruta del archivo a reproducir. El archivo de audio debe estar en formato OGG/Vorbis.
	$ ./tarea archivo.ogg
