# INF1304
# AULA Rede interna e externa
topologia inicial VS topologia ideal

zk-172.19.0.2/16           |         prod-172.19.0.5/16
    2181(porta exposta)    |            8080(porta corretamente exposta)
kf-172.19.0.3/16           |         cons-172.19.0.4/16
    9092(porta exposta)    |            8081(porta corretamente exposta) (Port Address Translator(internamente é 8080))
                           |
                           |
                           V

              ext-net            int-net
                 |                  |     
                 |-------prod-------|
                 |        zk--------|     
                 |-------cons-------|
                 |        kf--------|
     world-------|
