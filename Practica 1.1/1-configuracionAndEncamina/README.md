# Practica 1.1 - Configuración estática
## Ver interfaces de red
```sh
ip link
```
## Configurar direcciones ip
```sh
#VM1
$ ip addres add 10.0.0.1/24 dev eth0
$ ip link set dev eth0 up
$ ip route add default via 10.0.0.3
#VM2
$ ip addres add 10.0.0.2/24 dev eth0
$ ip link set dev eth0 up
$ ip route add default via 10.0.0.3
#VM3
$ ip addres add 10.0.0.3/24 dev eth0
$ ip link set dev eth0 up
$ ip addres add 192.168.0.3/24 dev eth1
$ ip link set dev eth1 up
#VM4
$ ip addres add 192.168.0.4/24 dev eth0
$ ip link set dev eth0 up
$ ip route add default via 192.168.0.3
```
## Habilitamos reenvio de paquetes
```sh
sysctl net.ipv4.ip_forward=1
```

## Probamos todo haciendo ping entre máquinas
```sh
#Desde VM1 a VM4
$ ping 192.168.0.4
#Desde VM1 a VM2
$ ping 10.0.0.2
```

