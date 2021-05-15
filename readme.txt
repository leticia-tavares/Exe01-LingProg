			Trabalho 1 de Linguagens de Progamação

OBS: Embora seja especificado no enunciado que os dados podem ser arbitrários, escolhi utilizar
dados reais para que a saída do programa fosse fiel a realidade e para poder verificar (e corrigir) o 
funcionamento das funções de cálculo de forma mais fácil.

-------------------------------------------------------------------------------------------------------------------
	O programa é compilado a partir do Makefile e seu comando make, que cria o executável 'covidBrasil'. 
Após seu uso, é possível rodar o comando make clean, para limpar os arquivos *.o e o executável. 
O arquivo de Makefile foi desenvolvido da forma como foi ensinado na disciplina de Computação II.

	Também pode ser compilado seguinte da forma:
g++ -Wall main.cpp estadual.cpp nacional.cpp dados.cpp auxiliares.cpp menu.cpp -o  covidBrasil

------------------------------------------------------------------------------------------------------------------
- Implementação/Funcionamento do programa 

	O programa possui uma classe Nacional e uma classe Estadual, na qual a classe Nacional é composta 
por objetos da classe Estadual. Cada objeto da classe Estadual representa um estado brasileiro.
Os objetos da classe Estadual são salvos em um vector para posterior uso na classe Nacional. 
Os dados referentes a Covid-19 estão salvos na classe Dados, criada para salvar todos os requisitos
necessários para a criação dos objetos da classe Estadual.
	O programa possui como interação com o usuário apenas a escolha de exibição do item desejado. 
Não há entrada de dados por parte do usuário.
	Os dados exibidos são reais e foram obtidos no link 
'https://news.google.com/covid19/map?hl=pt-BR&mid=%2Fm%2F015zxx&gl=BR&ceid=BR%3Apt-419'. O conjunto de dados
de óbitos é referente ao intervalo entre os dias 16 e 8 de Abril de 2021. As médias móveis são do dia 09.

----------------------------------------------------------------------------------------------------------------

- Arquivo estadual.cpp: define a classe Estadual que possui um construtor que recebe como parâmetros o nome, 
o vetor de óbitos e a média passada do estado. Possui como atributos privados uma string para o nome,
um vetor para os óbitos, a média móvel antiga, um vetor para média móvel a ser calculada e um double para
a variação a ser calculada. Cada atribtuo é configurado e acessado por seu conjunto de set e get.


-------------------------------------------------------------------------------------------------------------------

- Arquivo nacional.cpp:  define a classe Nacional que possui um construtor que recebe como parâmetros o nome, 
o vetor de estados do páis (vector <Estadual>) e a média passada nacional. Possui como atributos privados um 
vetor de objetos da classe Estadual, uma string para o nome, um inteiro com o valor de dias considerados pelo 
programa, um vetor para os óbitos, a média móvel antiga, um vetor para média móvel a ser calculada e um double para
a variação a ser calculada. Cada atribtuo é configurado e acessado por seu conjunto de set e get.

------------------------------------------------------------------------------------------------------------------

- Arquivo dados.cpp

Classe Dados:
Esta classe serve como base de dados para o programa. Possui como atributos públicos um vetor que guarda os 
nomes dos estados, um vetor para médias móveis de cada estado(datadas de 09/Abril), um vetor de vetor que 
guarda os óbitos de cada estado por ordem alfabética e do dados mais recente para o mais antigo. 

-------------------------------------------------------------------------------------------------------------

- Arquivo auxiliares.cpp: aqui estão definidas todas as funções necessárias para o funcionamento das classes 
Estadual e Nacional. São as seguintes:

vector <double> calcularMediaMovel (vector< int > numeroObitos) -> calcula a média móvel para o dia atual
e os dois seguintes
double calcularVariacaoMediaMovel (vector <double> vetorMediaMovel, double mediaAnterior) -> recebe o vetor
retornado pela função acima e a média de 7 dias atrás, retorna a variação entre a média atual e a antiga 
int calcularTotalObitosEstado (vector<int> obitos) -> calcula de forma acumulada o toal de óbitos noestado
int calcularTotalObitosPais (vector <vector< int >> obitos) -> calcula de forma acumulada o toal de óbitos no país

------------------------------------------------------------------------------------------------------------------

- Arquivo menu.cpp: interface do programa. Recebe a entrada do usuário e exibe uma das 5 opções desejadas. 

void exibeOp1 (Nacional pais)
void exibeOp2 (Nacional pais)
void exibeOp3 (Nacional pais)
void exibeOp4 (Nacional pais)
void exibeOp5 (Nacional pais)
void menu (Nacional pais)


-------------------------------------------------------------------------------------------------------------------

-Arquivo main.cpp: programa principal, responsável por criar os objetos das classes Estadual Nacional
e rodar o menu.

-------------------------------------------------------------------------------------------------------------------
