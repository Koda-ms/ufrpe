package questao04.negocio.beans;

import java.time.LocalDate;
import java.util.Objects;

public class Usuario {

	private String email;
	private String nome;
	private LocalDate dataNascimento;

	public Usuario(String email, String nome, LocalDate dataNascimento) {
		this.setEmail(email);
		this.setNome(nome);
		this.setDataNascimento(dataNascimento);
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		if(email != null) {
			this.email = email;
		}
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		if(nome != null) {
			this.nome = nome;
		}
	}

	public LocalDate getDataNascimento() {
		return dataNascimento;
	}

	public void setDataNascimento(LocalDate dataNascimento) {
		if(dataNascimento != null) {
			this.dataNascimento = dataNascimento;
		}
	}
	
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Usuario other = (Usuario) obj;
		return Objects.equals(dataNascimento, other.dataNascimento) && Objects.equals(email, other.email)
				&& Objects.equals(nome, other.nome);
	}
	
	 @Override
	public int hashCode() {
	     return Objects.hash(nome, email, dataNascimento);
	}

	@Override
	public String toString() {
		return String.format("%s", this.nome);
	}
}
