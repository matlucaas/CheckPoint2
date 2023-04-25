# CheckPoint2 - Edge Computing

## Integrantes do grupo:
+ BRUNO SILVA BASTOS 

+ GUILHERME DAHER 

+ GABRIEL FREITAS 

+ MATHEUS LUCAS 

## Sobre o projeto:
Este projeto é basicamente uma melhoria do nosso primeiro projeto feito no CP1, que captava a luminosidade do ambiente e de acordo com o nível da luminosidade retornava se a mesma estava boa ou ruim para a produção de vinhos por meio de ***leds*** e um ***buzzer***.

### Mas o que foi feito de novo?
Neste novo projeto, incluímos ferramentas que simulam o sensor DHT11, pois o mesmo não existe no simulador. Mas por que o uso deste sensor? O DHT11 é um sensor que consegue captar a umidade e a temperatura do ambiente, grandezas as quais são tão essenciais quanto a luminosidade na produção de vinho. Como foi dito anteriormente, no simulador em si este sensor não existe, mas usamos outra ferramenta para simulá-la.

### Componentes:
Além dos antigos componentes utilizados, como o LDR, o Buzzer e os LEDs (que também estão sendo utilizados tanto para sinalizar a luminosidade quantos as outras grandezas), adicionamos:

+ Um sensor de temperatura
+ Um LCD
+ Dois potenciômetros

### O que cada um destes faz?
Bom, é muito simples, o sensor de temperatura capta a temperatura do ambiente, um potenciômetro simula a umidade do ambiente, e conforme ele é girado, maior ou menor fica a umidade. Já o segundo potenciômetro tem o papel de controlar a tensão do LCD, fazendo com que ele funcione apropriadamente, e é este LCD que exibe se as 3 grandezas estão adequadas ou não, sendo elas a luminosidade, umidade e a temperatura. Além deste LCD, os leds e o buzzer que já estavam no antigo projeto também sinalizam se as grandezas estão em boas condições ou não.

## Como utilizar o projeto pelo simulador:
Para começar, entre no link abaixo:
+ https://www.tinkercad.com/things/fv3xi54HsJ2-brilliant-stantia-gaaris/editel
Agora, já no simulador, basta clicar no canto superior direito em "Iniciar simulação" ou clicar na tecla "S". Feito isso, agora vamos testar se as 3 grandezas estão sendo captadas normalmente. Clique no potenciômetro inferior e gire ele ou para a esquerda para diminuir ou para a direita para aumentar a UMIDADE, e é interessante que após testar, deixá-lo no nível adequado para testarmos as próximas para que o buzzer ou os LEDs não fiquem emitindo nenhum alerta, faça isso também com os próximos sensores. Clique no sensor de temperatura ao lado, e aumente ou abaixe a temperatura do ambiente para ver até quando a temperatura está "OK", faça isso também com o LDR ao lado, que ao ser clicado, aparece um índice de luminosidade, que conforme é aumentado e quanto mais luz tiver no ambiente, pior será para a qualidade dos vinhos, e tudo isso é alertado no nosso projeto, então sempre que alguma dessas grandezas estiver fora do normal, o buzzer e os LEDs irão notificar.