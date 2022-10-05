package questao02;

import java.time.LocalDate;

public class Funcionario extends Pessoa{
	
	static final double SALARIO_TETO_IMPOSTO = 10200;
	private double salario;
		
	public Funcionario(String nome, LocalDate dataNascimento, double salario) {
		super(nome, dataNascimento);
		this.salario = salario;
	}

	public double getSalario() {
		return salario;
	}

	public void setSalario(double salario) {
		this.salario = salario;
	}
	
	public double calcularImpostoDevido() {
		
		double imposto = 0;
		if(salario <= SALARIO_TETO_IMPOSTO) {
			imposto = salario * 0.05;
		} else {
			imposto = salario * 0.075;
		}
		return imposto;
	}

	@Override
	public String toString() {
		return super.toString() + String.format("Salário: R$%,.2f | Imposto: R$%,.2f", salario, calcularImpostoDevido());
	}
	
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (!super.equals(obj))
			return false;
		if (getClass() != obj.getClass())
			return false;
		Funcionario other = (Funcionario) obj;
		return Double.doubleToLongBits(salario) == Double.doubleToLongBits(other.salario);
	}

}
