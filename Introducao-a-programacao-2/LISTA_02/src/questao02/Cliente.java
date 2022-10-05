package questao02;

import java.time.LocalDate;

public class Cliente extends Pessoa{
	
	private long codigo;
	
	public Cliente(String nome, LocalDate dataNascimento, long codigo) {
		super(nome, dataNascimento);
		this.codigo = codigo;
	}
	
	public long getCodigo() {
		return codigo;
	}

	public void setCodigo(long codigo) {
		this.codigo = codigo;
	}

	@Override
	public String toString() {
		return super.toString() + " Código: " + codigo + " |";
	}
	
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (!super.equals(obj))
			return false;
		if (getClass() != obj.getClass())
			return false;
		Cliente other = (Cliente) obj;
		return codigo == other.codigo;
	}
}
