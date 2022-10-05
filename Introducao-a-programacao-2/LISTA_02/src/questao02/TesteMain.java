package questao02;

import java.time.LocalDate;

public class TesteMain {

	public static void main(String[] args) {
		
		RepositorioPessoas pessoas = new RepositorioPessoas();
		
		//Instancia as pessoas ao sistema mais uma repetida em cada array
		Pessoa[] clientes = {
				new Cliente("Jéssica", LocalDate.of(2000, 3, 04), 92458732),
				new Cliente("David", LocalDate.of(1967, 8, 20), 12345678),
				new Cliente("Bruno", LocalDate.of(1993, 6, 30), 85423679),
				new Cliente("Eliza", LocalDate.of(1961, 10, 1), 12450364), //60 anos
				new Cliente("Carla", LocalDate.of(1960, 12, 12), 78460259), // 61 anos
				new Cliente("David", LocalDate.of(1967, 8, 20), 12345678) //Pessoa repetida
		};
		
		Pessoa[] funcionarios = {
				new Funcionario("Pedro", LocalDate.of(1962, 2, 16), 5200), //60 anos
				new Funcionario("Cássia", LocalDate.of(1982, 9, 22), 4500),
				new Funcionario("Lívia", LocalDate.of(1965, 11, 10), 6000),
				new Funcionario("João", LocalDate.of(1957, 1, 24), 3450), //65 anos
				new Funcionario("Lívia", LocalDate.of(1965, 11, 10), 6000), //Pessoa repetida
				new Funcionario("Amanda", LocalDate.of(1983, 7, 3), 2800)
		};
		
		Pessoa[] gerentes = {
				new Gerente("Marcos", LocalDate.of(1989, 4, 30), 10500, "Marketing"),
				new Gerente("Alberto", LocalDate.of(1961, 5, 28), 9330, "Compras"), //60 anos
				new Gerente("Márcia", LocalDate.of(1974, 6, 15), 9450, "Projetos"),
				new Gerente("Vanessa", LocalDate.of(1993, 10, 1), 10612, "Marketing"),
				new Gerente("Tiago", LocalDate.of(1972, 8, 31), 11200, "Contas"),
				new Gerente("Márcia", LocalDate.of(1974, 6, 15), 9455, "Projetos"), //Pessoa repetida
		};
		
		//Adiciona as pessoas ao ArrayList
		for(Pessoa c : clientes) {
			pessoas.cadastrarPessoas(c);
		}
		
		for(Pessoa f : funcionarios) {
			pessoas.cadastrarPessoas(f);
		}
		
		for(Pessoa g : gerentes) {
			pessoas.cadastrarPessoas(g);
		}
		
		//Execução dos métodos da lista 
		System.out.println("\n----- Pessoas Maioridade -----");
		for(Pessoa pessoaIdosa : pessoas.listarPessoasMaioresIdade()) {
			if(pessoaIdosa instanceof Cliente || pessoaIdosa instanceof Funcionario) {
				System.out.println(pessoaIdosa);
			}
		}
		
		System.out.println("\n----- Clientes Maioridade -----");
		for(Pessoa pessoaIdosa : pessoas.listarClientesMaioresIdade()) {
			if(pessoaIdosa instanceof Cliente) {
				System.out.println(pessoaIdosa);
			}
		}
		
		System.out.println("\n----- Funcionários com salário maior que R$9.500 -----");
		for(Pessoa funcionario : pessoas.listarFuncionariosComSalarioMaiorQue(9500)) {
			if(funcionario instanceof Funcionario) {
				System.out.println(funcionario);
			}
		}
		
		System.out.println("\n----- Gerentes que atuam na mesma área -----");
		for(Pessoa gerente : pessoas.listarGerentesDaArea("Marketing")) {
			if(gerente instanceof Funcionario) {
				System.out.println(gerente);
			}
		}
	}
}