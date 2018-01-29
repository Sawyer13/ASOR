# DNS Server
## Incluir un dominio en local
```sh
$ nano /etc/bind/named.conf
#
# Introducir:
#
# zone "labfdi.es." {
# 	type master;
#	file "/etc/bind/db.labfdi.es";
# }
#
$ sudo service bind9 start
#
# Comprobar que todo esta guay con
$ dig labfdi.es.
```
