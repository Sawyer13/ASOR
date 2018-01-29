# DNI Client
## Obtener la dirección ip mediante un dominio
```sh
$ dig @a.root-servers.net informatica.ucm.es
$ dig @g.nic.es informatica.ucm.es
$ dig @crispin.sim.ucm.es informatica.ucm.es
```

## Obtener la información de SOA
```sh
$ dig SOA @crispin.sim.ucm.es ucm.es
```

## Obtener mail MX
```sh
$ dig MX @crispin.sim.ucm.es fdi.ucm.es
```

## Obtener el dominio en base a una IP
```sh
$ host -v 147.96.85.71 a.root-servers.net
$ host -v 147.96.85.71 a.in-addr-servers.arpa
$ host -v 147.96.85.71 z.arin.net.
$ host -v 147.96.85.71 ucdns.sis.ucm.es
```
