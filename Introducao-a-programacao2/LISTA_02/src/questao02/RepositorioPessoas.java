package questao02;

import java.util.ArrayList;

public class RepositorioPessoas {

	private ArrayList<Pessoa> pessoas;
	
	public RepositorioPessoas() {
		super();
		this.pessoas = new ArrayList<>();
	}
	
	public void cadastrarPessoas(Pessoa pessoa) {
		
		if(pessoa != null) {
			String nome = pessoa.getNome();
			boolean pessoaJaCadastrada = false;
			for(Pessoa p : pessoas) {
				if(p.getNome().equals(nome)) {
					pessoaJaCadastrada = true;
					System.out.println("Pessoa " + p.getNome() + " já cadastrada.");
				}
			}
			if(!pessoaJaCadastrada) {
				this.pessoas.add(pessoa);
			}
		}
	}
	
	public ArrayList<Pessoa> listarPessoasMaioresIdade(){
		
		ArrayList<Pessoa> pessoasMaioresIdade = new ArrayList<>();
		for(Pessoa p : pessoas) {
			if(p.calcularIdade() >= 60) {
				pessoasMaioresIdade.add(p);
			}
		}
		return pessoasMaioresIdade;
	}
	
	public ArrayList<Cliente> listarClientesMaioresIdade(){
		
		ArrayList<Cliente> clientesMaioresIdade = new ArrayList<>();
		for(Pessoa c : pessoas) {
			if(c instanceof Cliente && c.calcularIdade() >= 60) {
				clientesMaioresIdade.add((Cliente) c);
			}
		}
		return clientesMaioresIdade;
	}
	
	public ArrayList<Funcionario> listarFuncionariosComSalarioMaiorQue(double salario){
		
		ArrayList<Funcionario> funcionariosComSalarioMaior = new ArrayList<>();
		for(Pessoa f : pessoas) {
			if(f instanceof Funcionario && ((Funcionario)f).getSalario() > salario) {
				funcionariosComSalarioMaior.add((Funcionario) f);
			}
		}
		return funcionariosComSalarioMaior;
	}
	
	public ArrayList<Gerente> listarGerentesDaArea(String area){
		
		ArrayList<Gerente> gerentesMesmaArea = new ArrayList<>();
		for(Pessoa g : pessoas) {
			if(g instanceof Gerente && ((Gerente)g).getArea().equals(area)) {
				gerentesMesmaArea.add((Gerente) g);
			}
		}
		return gerentesMesmaArea;
	}

}
