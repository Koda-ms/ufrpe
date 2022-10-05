package questao03;

import java.time.LocalDate;
import java.time.Period;

public class Pessoa {

	private String cpf;
	private String nome;
	private LocalDate dataNascimento;
	//private LocalDate dataHoje;
	
	/*public Pessoa() {
		this.dataHoje = LocalDate.now();
	}*/

	public Pessoa(String cpf, String nome, LocalDate dataNascimento) {
		this.cpf = cpf;
		this.nome = nome;
		this.dataNascimento = dataNascimento;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public LocalDate getDataNascimento() {
		return dataNascimento;
	}

	public void setDataNascimento(LocalDate dataNascimento) {
		this.dataNascimento = dataNascimento;
	}

	public int calcularIdade() {
		LocalDate dataHoje = LocalDate.now();
		
		Period periodo = Period.between(getDataNascimento(), dataHoje);
		
		return periodo.getYears();
	}
}
