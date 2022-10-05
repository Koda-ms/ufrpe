package questao02;

import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;
import java.util.Objects;

public abstract class Pessoa {

	private String nome;
	private LocalDate dataNascimento;

	public Pessoa(String nome, LocalDate dataNascimento) {
		this.nome = nome;
		this.dataNascimento = dataNascimento;
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

	@Override
	public String toString() {
		String dataFormatada = DateTimeFormatter.ofPattern("dd/MM/YYYY").format(dataNascimento);
		return "Nome: " + nome + " | Data de Nascimento: " + dataFormatada + " | Idade: " + calcularIdade() + " anos | ";
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Pessoa other = (Pessoa) obj;
		return Objects.equals(dataNascimento, other.dataNascimento) && Objects.equals(nome, other.nome);
	}

}
