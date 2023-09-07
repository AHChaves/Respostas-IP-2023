###Perfil
Um perfil do sistema é um registro único composto pelas seguintes
informações:
• ID: Identificador único do perfil. Esse identificador deverá ser
utilizado para fazer todas as ligações entre um perfil e qualquer
outro elemento do sistema.
• Nome: Nome do usuário
• E-mail: E-mail do usuário. Deve ser um e-mail válido no sentido de
que deve possuir um @ seguido de um domínio. O e-mail que é deverá
ser utilizado para logar no sistema. Não pode existir mais de um
e-mail igual cadastrado no sistema.
• Senha: Senha utilizada para logar no sistema.

###Ações:
• Logar: O ID ou e-mail mais a senha devem ser digitados e, caso
estejam cadastrados no sistema, o perfil encontrado passa a estar
LOGADO.
• Deslogar: O perfil atualmente logado é deslogado.
• Listar: Lista, em formato de tabela, todos os perfis cadastrados
no sistema. O sistema deve oferecer as opções de listar ordenado
pelo ID, nome ou e-mail.
• Buscar: Buscar por perfis através de parte do nome e/ou e-mail. O
sistema deve oferecer as opções de listar ordenado pelo ID, nome
ou e-mail.
• Visitar: Ativa um determinado perfil para receber ações dos outros
módulos, mas não troca o usuário logado. É semelhante ao processo
de abrir um perfil para verificar o que ele possui.

###Postagens
Uma postagem é o registro de uma ou mais imagens com descrição associado
à um usuário. As informações de uma postagem são:

• ID: Identificador único fornecido pelo sistema para identificar uma
postagem.
• Imagens: Lista de imagens em ASCII.
• Descrição: Texto descritivo a ser impresso logo após a(s)
imagem(ns).
• Comentários: Lista de comentários feitos por outros usuários na
referida postagem.
• Curtidas: Lista dos usuários que curtiram a postagem.

###Ações:
• Postar: Realiza uma postagem no perfil atualmente logado.
• Apagar: Remove uma postagem da lista de postagens do perfil logado.
• Editar: Atualiza uma postagem da lista de postagens do perfil
logado.
• Listar: Lista as postagens de um perfil (do perfil ativo, não do
usuário logado).
• Detalhar: Abre uma postagem e mostra todos os detalhes dela (dados
da postagem, usuários que curtiram e os comentários).

###Comentários
Um comentário é uma mensagem deixada por um perfil em uma postagem. As
informações de uma postagem são:
• ID: Identificador único fornecido pelo sistema para identificar
um comentário.
• Perfil: Identificador do perfil que comentou na postagem.
• Mensagem: Texto deixado como comentário na postagem.
Ações:
• Comentar: Realiza um comentário na postagem atual. Utiliza o perfil
logado como dono do comentário.
• Apagar: Remove o comentário feito pelo perfil.
• Editar: Atualiza um comentário da lista de comentários da postagem.
• Listar: Lista os comentários de uma postagem.

###Curtidas
Uma curtida é um registro de que determinado perfil curtiu uma postagem.
Ações:
• Curtir: O perfil logado curte uma postagem.
• Descutir: O perfil logado deixa de curtir uma postagem.
Especificações
O objetivo deste trabalho é simular o sistema do Instagram, ou seja, o
programa é o sistema inteiro tendo acesso a todas as informações, não
um usuário específico.
O comportamento fica a cargo da implementação, mas na medida do possível,
deve ser o mais semelhante possível ao Instagram. Cada grupo tem a



liberdade de criar sua própria interface com o usuário do sistema, sendo
que a facilidade de uso interfere na nota final.
Cada grupo pode ser formado por ATÉ três alunos, podendo conter alunos
de turmas e subturmas diferentes, mas obedecendo as seguintes restrições:
• No sorteio da apresentação, ficará definido dia e horário e todos
os alunos deverão estar presentes, cabendo ao(s) aluno(s)
apresentar liberação formal do professor da outra aula para
participar.
• A data de entrega (até 11/11/2023 – 23h59) é a mesma independente
do dia da apresentação, portanto pode haver prazos diferentes para
a apresentação dependendo do resultado do sorteio.
• Os integrantes do grupo devem ser postados como comentário PÚBLICO
(não privado na atividade) na atividade do trabalho final até o dia
17/09/2023. O professor manterá a lista de grupos e integrantes
atualizada. A não postagem implica em trabalho realizado
individualmente.
O professor fornecerá um trecho de código e uma ferramenta que devem
OBRIGATORIAMENTE ser utilizados no trabalho.