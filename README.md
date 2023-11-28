* Este projeto tem como objetivo o desenvolvimento de uma API para um Simulador de Sistemas Dinâmicos que opera de acordo com a Teoria Geral de Sistemas, teoria esta que, desenvolvida pelo The Ratio Club, provê uma linguagem unificada capaz de organizar qualquer conhecimento científico.


* Sprint 1 - Projeto da API do simulador de Sistemas Dinâmicos.

    -> O estudante irá apresentar ao professor um arquivo PDF, de nome "[nome_estudante]_sprint1.pdf", contendo o projeto da API do seu simulador que executa modelos de simulação descritos segundo paradigma de dinâmica de sistemas. Para isso, ele deve responder as questões de 1 a 4 contidas no enunciado do trabalho individual. O diagrama UML contendo a API deve ser construído em software destinado à modelagem UML, como o Astath ou Jude Communit.


* Sprint 2 - Classes Concretas na forma canônica + testes funcionais.

    -> O código do  simulador deve ser armazenado em uma estrutura que permita sua fácil manutenção e evolução. Para isso, todos os arquivos fonte gerados para o projeto devem ser armazenados em um único diretorio, que recebe o nome do produto principal, os arquivos que formam o produto deve ser armazenados em um subdiretório chamado "src", os arquivos de testes armazenados no diretório "test" e os arquivos binarios (exe, dll, lib, so) no diretorio "bin". Desta maneira haverá 3 arquivos "main.cpp" - 1 para o produto, 1 para os testes funcionais e outro para os testes unitários.

    -> Os 3 testes funcionais devem ser separados em 3 diferentes funções. Estas 3 funções devem ser colocadas no arquivo "funcional_tests.cpp" e suas assinaturas no arquivo "funcional_tests.h" que deve ser incluída no arquivo "main.cpp" (testesRegressivos) do subdiretório "\MyVensin\test\funcional".


* Sprint 3 - Documentação de código em Doxygen (com gráficos).

    -> Os alunos devem documentar o código do simulador por meio da ferramenta Doxygen que pode ser obtida em: http://www.doxygen.nl/download.html. É essencial que os gráficos de dependência de arquivos e das estruturas de classes sejam gerados. Para isso, muitas vezes é necessário instalar a ferramenta Graphviz disponivel em https://www.graphviz.org/. Veja explicações detalhadas em em: http://www.doxygen.nl/manual/diagrams.html.


* Sprint 4 - API definida por interfaces separadas das classes concretas + testes unitários.

    -> Para cada classe do produto, por exemplo "System" haverá um arquivo "*.h" e um arquivo "*.cpp" contendo os testes unitários desta classe. O nome desses arquivos devem ser formados pelo nome da classe precedido pelo prefixo "unit_", por exemplo "unit_System.h" e "unit_System.cpp". Cada um dos metodos das classes deve ter uma função independente de teste unitário para testá-lo cujo nome é formado pelo prefixo "unit_" concatenado ao nome da classe e ao nome do método que será testado, por exemplo "void unit_System_getValue(void)". Cada arquivo "*.cpp" deve conter uma função que invoca todos os testes unitários e cujo nome é formado pelo prefixo "run_unit_test_" concatenado o nome da classe testada. Neste exemplo o nome seria "void run_unit_test_System(void)".

    -> Para funções de escopo global, o nome das funções que implementam os testes unitários devem anexar o prefixo "unit_" ao nome da função testada. Por exemplo, a função de escopo global "...minhaFuncao(...)" deve ser testada pela função "void unit_minhaFunca(void)" e os códigos dos testes unitários devem ser armazenados no arquivo "unit_tests.cpp" e as assinaturas no arquivo "unit_tests.h". Esse arquivo "*.cpp" deve conter uma função que invoca todos os testes unitários e cujo nome é formado pelo prefixo "run_unit_test_" concatenado à string "globals". Neste exemplo o nome seria "void run_unit_test_globals(void)".

    -> O arquivo "main.cpp" do subdiretório "\MyVensin\test\unit" deve incluir todos os arquivos .h e invocar o metodo "void run_unit_test_...()" de cada arquivo "*.cpp".


* Sprint 5 - Arquitetura em camadas: componentização + fábricas.

    -> A implementação correta de uma arquitetura em camadas exigirá a componentização (DLLs, SOs) do seu produto.


* Sprint 6 - Handle body.

    -> Aplique o idioma Handle-Body, também conhecido como Bridge, em todas suas classes concretas. Faz sentido aplica-lo às interfaces? Para isso, utilize o template fornecido pelo professor.

    -> Tomando como base o arquivo main.cpp, produza um teste unitário que verifique o uso que você fez desta template.

    -> O arquivo compactado possui 4 arquivos em seu interior: o template do pattern handle-body, o main.cpp que funciona como um teste unitário para o template, a interface de System e uma implementação de System sem o uso do template. A questão que coloco é: "como aplicar a template à interface System para desenvolvermos uma implementação equivalente à implementação fornecida?". Depois de responder essa pergunta, o desafio de vocês é aplicar o template do pattern handle-body aos outros objetos da biblioteca.


* Sprint 7 - Composite (bônus).

    -> Aplique o padrão de projeto composite e consiga que sistemas possam ser feitos de sistemas que, por sua vez, sejam feitos por outros sistemas e assim por diante...
