package questao03.receita;

import java.time.LocalDateTime;

public class LicensaBasica extends Receita{
	
	private int totalContas;
	
	public LicensaBasica(LocalDateTime data, String descricao, int totalContas) {
		super(data, descricao);
		this.setTotalContas(totalContas);
	}

	public void setTotalContas(int totalContas) {
		if(totalContas >= 0) {
			this.totalContas = totalContas;
		}
	}
	
	@Override
	public LocalDateTime getData() {
		return super.getData();
	}
	
	@Override
	public String getDescricao() {
		return super.getDescricao();
	}

	@Override
	public String getTipo() {
		return "Receita";
	}

	@Override
	public double calcularTotal() {
		return this.totalContas * 20.0;
	}

	@Override
	public String toString() {
		return String.format("%d", totalContas);
	}
}
