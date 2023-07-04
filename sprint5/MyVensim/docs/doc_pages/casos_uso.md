@page subpage1 Casos de uso

@tableofcontents

@section subsec1 Caso 1

Fluxo sem origem e sem destino

Nesse caso, a API deve permitir a criação de
um fluxo que não possui uma origem específica nem um destino definido. Isso significa
que o fluxo está livre para ser conectado a sistemas em qualquer ponto.
~~~cpp

    Flow f1(); ///< Create a Flow object
    f1.setName("f1"); ///< Set the name of the flow
    f1.setSource(NULL); ///< Set the source of the flow
    f1.setTarget(NULL); ///< Set the target of the flow

    /// Constructor
    Flow f1("f1", NULL, NULL); ///< Create a Flow object with specified name, source, and target
~~~
@section subsec2 Caso 2
Um sistema isolado sem fluxo

 A API deve permitir a modelagem de sistemas
que não possuem fluxo conectado a eles. Esses sistemas são considerados isolados,
ou seja, não trocam informações com outros sistemas por meio de fluxos.

~~~cpp
System s1();
s1.setName(&quot;s1&quot;);
s1.setValue(0.1);
//constructor
System s1(&quot;s1&quot;, 0.1);
~~~

@section subsec3 Caso 3

Um fluxo conectado a apenas um sistema no destino

Nesse caso, a API
deve permitir a criação de um fluxo que tem origem em um sistema e se conecta a
apenas um sistema no destino. Essa configuração permite a transferência de
informações de um sistema para outro de forma direta.

~~~cpp
System s1(&quot;s1&quot;, 0.1);
Flow f1(&quot;f1&quot;, NULL, &amp;s1);
~~~

@section subsec4 Caso 4

Um fluxo conectado a apenas um sistema na origem 

Nesse caso, a API
deve permitir a criação de um fluxo que tem origem em um sistema e se conecta a
apenas um sistema na origem. Essa configuração permite que um sistema receba
informações de um único sistema de origem.

~~~cpp
System s1(&quot;s1&quot;, 0.1);
Flow f1(&quot;f1&quot;, &amp;s1, NULL);
~~~
@section subsec5 Caso 5

Um fluxo conectado a um sistema na origem e no destino

 A API deve ser
capaz de lidar com fluxos que conectam um sistema em sua origem a outro
sistema
no destino. Essa configuração permite a transferência de informações bidirecionais
entre os sistemas.

~~~cpp
System s1(&quot;s1&quot;, 0.1);
System s2(&quot;s2&quot;, 0.1);
Flow f1(&quot;f1&quot;, &amp;s1, &amp;s2);
~~~
@section subsec6 Caso 6
Um sistema que serve de origem para dois ou mais sistemas

A API deve
permitir a criação de um sistema que atua como origem para múltiplos sistemas.

Isso significa que o sistema envia informações para diferentes sistemas,
possibilitando uma distribuição de dados eficiente.

~~~cpp
System s1(&quot;s1&quot;, 0.1);
Flow f1(&quot;f1&quot;, &amp;s1, NULL);
Flow f2(&quot;f2&quot;, &amp;s1, NULL);
~~~

@section subsec7 Caso 7
Um sistema que serve de destino para dois ou mais sistemas 

Nesse caso,
a API deve suportar a modelagem de um sistema que serve como destino para
múltiplos sistemas. Isso significa que o sistema recebe informações de diferentes
fontes, permitindo a consolidação e processamento dos dados recebidos.

~~~cpp
System s1(&quot;s1&quot;, 0.1);
Flow f1(&quot;f1&quot;, NULL, &amp;s1);
Flow f2(&quot;f2&quot;, NULL, &amp;s1);
~~~

@section subsec8 Caso 8
Criação de um modelo e adicionando 3 sistemas e 3 fluxos e executando-o

~~~cpp
Model model(&quot;model1&quot;);
//adding system and flux in the model
model.add(&amp;s1);
model.add(&amp;s2);
model.add(&amp;s3);
model.add(&amp;f1);
model.add(&amp;f2);
model.add(&amp;f3);
//adding system and flux in the model
model.run(0,10,0.1);
~~~
@section subsec9 Caso Exponential:


~~~cpp
//create a exponential class
class Exponential : public Flow{
   double execute(void){
        return 0.01.getSource().getValue();
    }
};
//Execute the model
Model model(&quot;model1&quot;);
System s1(&quot;s1&quot;, 0.1);
System s2(&quot;s2&quot;, 0.1);
Exponential f1(&quot;exp&quot;, &amp;s1, &amp;s2);
model.add(&amp;s1);
model.add(&amp;s2);
model.add(&amp;f1);
model.run(0,10,0.1);
~~~
@section subsec10 Caso Logistica:

~~~cpp
class Logistic : public Flow{
   double execute(void){
        return 0.01.getSource().getValue() *

(1 - getSource().getValue() / getMax());

    }
    double getMax(void){
        return max;
    }
    private:
        double max;
};
System s1(&quot;s1&quot;, 0.1);
System s2(&quot;s2&quot;, 0.1);
Logistic f1(&quot;logi&quot;, &amp;s1, &amp;s2);
model.add(&amp;s1);

model.add(&amp;s2);
model.add(&amp;f1);
model.run(0,10,0.1);
~~~

@section subsec11 Caso Sistema exponential

~~~cpp
model m1(&quot;m1&quot;);
System q1(&quot;s1&quot;, 100);
System q2(&quot;s2&quot;, 0);
System q3(&quot;s3&quot;, 100);
System q4(&quot;s4&quot;, 0);
System q5(&quot;s5&quot;, 0);
Exponential f(&quot;f&quot;, &amp;q1, &amp;q2);
Exponential g(&quot;g&quot;, &amp;q1, &amp;q3);
Exponential u(&quot;u&quot;, &amp;q3, &amp;q4);
Exponential v(&quot;v&quot;, &amp;q4, &amp;q1);
Exponential t(&quot;w&quot;, &amp;q2, &amp;q3);
Exponential r(&quot;r&quot;, &amp;q2, &amp;q5);
m1.add(&amp;q1);
m1.add(&amp;q2);
m1.add(&amp;q3);
m1.add(&amp;q4);
m1.add(&amp;q5);
m1.add(&amp;f);
m1.add(&amp;g);
m1.add(&amp;u);
m1.add(&amp;v);
m1.add(&amp;t);
m1.add(&amp;r);
m1.run(0,10,0.1);
~~~