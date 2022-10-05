package questao02;

import java.time.LocalDate;
import java.util.Objects;

public class Gerente extends Funcionario{

	private String area;
	
	public Gerente(String nome, LocalDate dataNascimento, double salario, String area) {
		super(nome, dataNascimento, salario);
		this.area = area;
	}

	public String getArea() {
		return area;
	}

	public void setArea(String area) {
		this.area = area;
	}

	@Override
	public String toString() {
		return super.toString() + " Área: " + area + " |";
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Gerente other = (Gerente) obj;
		return Objects.equals(area, other.area);
	}

}
