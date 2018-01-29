# Estados de una conexión TCP
```sh
# MV1 - Abrir un puerto TCP en el puerto 7777
$ nc -l -p 777
# Comprobar el estado de la conexión
$ netstat -puta
# Conectarse al servidor netstat
$ nc 192.168.0.1 7777
# Reiniciar el servidor con la opción -s
$ nc -l -p 7777 -s 192.168.0.1
```
