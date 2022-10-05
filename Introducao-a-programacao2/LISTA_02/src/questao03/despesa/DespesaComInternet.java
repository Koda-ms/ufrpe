package questao03.despesa;

import java.time.LocalDateTime;

public class DespesaComInternet extends Despesa{
	public static final double VALOR_FIXO_20GB = 90.90;
	public static final double VALOR_FIXO_100GB = 240.90;
	public static final double VALOR_FIXO_500GB = 590.90;
	
	private double dadosTrafegados;
	
	public DespesaComInternet(LocalDateTime data, String descricao, double dadosTrafegados) {
		super(data, descricao);
		this.setDadosTrafegados(dadosTrafegados);
	}

	public void setDadosTrafegados(double dadosTrafegados) {
		if(this.dadosTrafegados >= 0) {
			this.dadosTrafegados = dadosTrafegados;
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
		return "Despesa";
	}

	@Override
	public double calcularTotal() {
		double gastoTotal = 0;
		
		if(this.dadosTrafegados >= 20) {
			gastoTotal = VALOR_FIXO_20GB + (3.9 * (this.dadosTrafegados - 20));
		} else if(this.dadosTrafegados >= 100) {
			gastoTotal = VALOR_FIXO_100GB + (4.4 * (this.dadosTrafegados - 100));
		} else if (this.dadosTrafegados >= 500) {
			gastoTotal = VALOR_FIXO_500GB + (5.1 * (this.dadosTrafegados - 500));
		} else {
			gastoTotal = VALOR_FIXO_20GB; //caso menor que 20GB
		}
		return gastoTotal;
	}

	@Override
	public String toString() {
		return String.format("%.1f GB", dadosTrafegados);
	}
}
