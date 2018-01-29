# Practica 1.1 - Configuración dinámica
## Si venimos de la configuración estática
```sh
# Para VM1
$ ip addr del 10.0.0.1 dev eth0
# Para VM2
$ ip addr del 10.0.0.2 dev eth0
# Para VM4
$ ip addr del 192.168.0.4 dev eth0
```

## Configurar el servidor DHCP
```sh
# En VM3 - Editamos el fichero /etc/dhcp/dhcp.conf y añadimos
subnet 10.0.0.0 netmask 255.255.255.0 {
	range 10.0.0.50 10.0.0.100
	option routers 10.0.0.3
	option broadcast-address 10.0.0.255
}
subnet 192.168.0.0 netmask 255.255.255.0 {
	range 192.168.0.50 192.168.0.100
	option routers 192.168.0.3
	option broadcast-address 192.168.0.255
}

# Arrancamos el servicio
$ service isc-dhcp-server start
```

## Pedimos direcciones ip al servidor en cada VM1
```sh
$ dhclient -d eth0
```

# Configuración durante el arranque del sistema automática
```sh
# Añadimos a /etc/network/interfaces
 
# The loopback network interface
# auto lo
# iface lo inet loopback
# 
# auto eth0
# iface eth0 inet dchp
```
